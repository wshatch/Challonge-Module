<?php

function challonge_publish_confirm(&$form_state, $node)
{
    $form = array(
        'nid' => array(
            '#type' => 'value',
            '#value' => $node->nid,
        )
    );

    $form_state['storage']['node'] = $node;

    return confirm_form($form,
        t('Are you sure you want to publish this tournament %title in Challonge?', array('%title' => $node->title)),
        isset($_GET['destination']) ? $_GET['destination'] : 'node/'. $node->nid,
        t('This action cannot be undone.'),
        t('Publish'),
        t('Cancel')
    );
}

function challonge_publish_confirm_submit($form, &$form_state)
{
    $node = $form_state['storage']['node'];
    if ($form_state['values']['confirm']) {
        $xml = helper_publish_tournament($node->tournament_id);
        if ($xml->error)
        {
            drupal_set_message(t('Error publishing the tournament: @error', array('@error' => $xml->error)), 'error');
        }
        else
        {
            drupal_set_message(t('Tournament published.'), 'status');
        }
    }

    drupal_goto('node/' . $node->nid);
}

function challonge_start_confirm(&$form_state, $node)
{
    $form = array(
        'nid' => array(
            '#type' => 'value',
            '#value' => $node->nid,
        )
    );

    $form_state['storage']['node'] = $node;

    return confirm_form($form,
        t('Are you sure you want to start this tournament %title in Challonge?', array('%title' => $node->title)),
        isset($_GET['destination']) ? $_GET['destination'] : 'node/'. $node->nid,
        t('This action cannot be undone.'),
        t('Start'),
        t('Cancel')
    );
}

function challonge_start_confirm_submit($form, &$form_state)
{
    $node = $form_state['storage']['node'];
    if ($form_state['values']['confirm']) {
        $xml = helper_start_tournament($node->tournament_id);
        if ($xml->error)
        {
            drupal_set_message(t('Error starting the tournament: @error', array('@error' => $xml->error)), 'error');
        }
        else
        {
            drupal_set_message(t('Tournament started.'), 'status');
        }
    }

    drupal_goto('node/' . $node->nid);
}
