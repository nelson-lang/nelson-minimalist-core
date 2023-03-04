//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif
#include "MainEvaluator.hpp"
#include "BasicTerminal.hpp"
#include "BuiltInFunctionDefManager.hpp"
#include "Clear.hpp"
#include "ClearGlobal.hpp"
#include "Localization.hpp"
#include "PathFuncManager.hpp"
#include "i18n.hpp"
#include "NelsonConfiguration.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
Evaluator*
createMainEvaluator(NELSON_ENGINE_MODE _mode, const std::wstring& lang, bool minimizeWindow)
{
    Evaluator* mainEvaluator = (Evaluator*)NelsonConfiguration::getInstance()->getMainEvaluator();
    size_t mainEvaluatorID = 0;
    if (mainEvaluator == nullptr) {
        Context* context = nullptr;
        try {
            context = new Context;
        } catch (std::bad_alloc&) {
            context = nullptr;
        }
        std::wstring effectiveLang = Localization::Instance()->initializeLocalization(lang);
        NelsonConfiguration::getInstance()->setMainGuiObject(nullptr);

        if (context != nullptr) {
            std::string msg = _("This mode is not yet implemented.\n");
            switch (_mode) {
            case ADVANCED_ENGINE:
            case ADVANCED_TERMINAL:
            case GUI:
            case ADVANCED_SIO_CLIENT:
            case BASIC_ENGINE: {
                fprintf(stderr, "%s", msg.c_str());
                exit(1);
            } break;
            case BASIC_TERMINAL: {
                BasicTerminal* nlsTerm = nullptr;
                try {
                    nlsTerm = new BasicTerminal();
                } catch (std::bad_alloc&) {
                    nlsTerm = nullptr;
                }
                if (nlsTerm != nullptr) {
                    mainEvaluator = new Evaluator(context, nlsTerm, false, mainEvaluatorID);
                }
            } break;
            default: {
                std::string _msg = _("unknow engine.\n");
                fprintf(stderr, "%s", _msg.c_str());
                exit(1);
            } break;
            }
        }
        NelsonConfiguration::getInstance()->setMainEvaluator((void*)mainEvaluator);
        Localization::Instance()->setLanguage(effectiveLang, false);
    }
    return mainEvaluator;
}
//=============================================================================
bool
destroyMainEvaluator()
{
    Evaluator* mainEvaluator = (Evaluator*)NelsonConfiguration::getInstance()->getMainEvaluator();
    if (mainEvaluator != nullptr) {
        Context* ctxt = mainEvaluator->getContext();
        if (ctxt != nullptr) {
            // delete all functions (builtin, macros, variables)
            ClearAllVariables(mainEvaluator);
            ClearAllGlobalVariables(mainEvaluator);
            delete ctxt;
            ctxt = nullptr;
        }
        PathFuncManager::getInstance()->destroy();
        Interface* io = mainEvaluator->getInterface();
        if (io != nullptr) {
            int engineMode = NelsonConfiguration::getInstance()->getNelsonEngineMode();
            switch (engineMode) {
            case ADVANCED_SIO_CLIENT:
            case BASIC_SIO_CLIENT:
            case BASIC_ENGINE: {
            } break;
            case ADVANCED_ENGINE: {
            } break;
            case GUI: {
            } break;
            case BASIC_TERMINAL: {
                auto* nlsTerm = (BasicTerminal*)io;
                delete nlsTerm;
                nlsTerm = nullptr;
            } break;
            case ADVANCED_TERMINAL: {
            } break;
            default: {
            } break;
            }
        }
        BuiltInFunctionDefManager::getInstance()->destroy();
        Localization::Instance()->destroy();
        delete mainEvaluator;
        mainEvaluator = nullptr;
        NelsonConfiguration::getInstance()->setMainEvaluator(nullptr);
        return true;
    }
    return false;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
