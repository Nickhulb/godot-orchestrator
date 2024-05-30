// This file is part of the Godot Orchestrator project.
//
// Copyright (c) 2023-present Vahera Studios LLC and its contributors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef ORCHESTRATOR_SCRIPT_FUNCTIONS_COMPONENT_PANEL_H
#define ORCHESTRATOR_SCRIPT_FUNCTIONS_COMPONENT_PANEL_H

#include "editor/component_panels/component_panel.h"

class OrchestratorScriptView;

class OrchestratorScriptFunctionsComponentPanel : public OrchestratorScriptComponentPanel
{
    GDCLASS(OrchestratorScriptFunctionsComponentPanel, OrchestratorScriptComponentPanel);
    static void _bind_methods();

    enum ContextMenuIds
    {
        CM_OPEN_FUNCTION_GRAPH,
        CM_RENAME_FUNCTION,
        CM_REMOVE_FUNCTION
    };

    OrchestratorScriptView* _view;
    Button* _override_button{ nullptr };

protected:
    //~ Begin OrchestratorScriptComponentPanel Interface
    String _get_unique_name_prefix() const override { return "NewFunction"; }
    PackedStringArray _get_existing_names() const override;
    String _get_tooltip_text() const override;
    String _get_remove_confirm_text(TreeItem* p_item) const override;
    String _get_item_name() const override { return "Function"; }
    bool _populate_context_menu(TreeItem* p_item) override;
    void _handle_context_menu(int p_id) override;
    bool _handle_add_new_item(const String& p_name) override;
    void _handle_item_selected() override;
    void _handle_item_activated(TreeItem* p_item) override;
    bool _handle_item_renamed(const String& p_old_name, const String& p_new_name) override;
    void _handle_remove(TreeItem* p_item) override;
    void _handle_button_clicked(TreeItem* p_item, int p_column, int p_id, int p_mouse_button) override;
    Dictionary _handle_drag_data(const Vector2& p_position) override;
    //~ End OrchestratorScriptComponentPanel Interface

    //~ Begin Signal handlers
    void _show_function_graph(TreeItem* p_item);
    //~ End Signal handlers

    /// Default constructor
    OrchestratorScriptFunctionsComponentPanel() = default;

public:
    //~ Begin OrchestratorScriptViewSection Interface
    void update() override;
    //~ End OrchestratorScriptViewSection Interface

    /// Godot's notification callback
    /// @param p_what the notification type
    void _notification(int p_what);

    /// Construct the function component panel
    /// @param p_orchestration the orchestration
    explicit OrchestratorScriptFunctionsComponentPanel(Orchestration* p_orchestration, OrchestratorScriptView* p_view);
};

#endif // ORCHESTRATOR_SCRIPT_FUNCTIONS_COMPONENT_PANEL_H