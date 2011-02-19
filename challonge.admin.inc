<?php

/**
 * The admin page for the settings.
 */
function challonge_settings_form()
{
    $form = array(
        'challonge_api_key' => array(
            '#type' => 'textfield',
            '#title' => t('Challonge\'s API Key'),
            '#description' => t('To get your API Key at Challonge, go to your Account Settings on Challonge (https://challonge.com/user/edit). Click the "Password & API Key" tab to see your API Key. Just generate an API Key if you are missing one.'),
            '#default_value' => variable_get('challonge_api_key', ''),
            '#required' => true
        )
    );

    return system_settings_form($form);
}

