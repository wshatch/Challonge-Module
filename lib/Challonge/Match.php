<?php

/**
 * Challonge's Match API class
 */
class ChallongeMatch extends ChallongeAPI
{
    protected $tournament_id;

    public function __construct($tournament_id)
    {
        $this->tournament_id = $tournament_id;
    }

    public function reqIndex()
    {
        return $this->request("/{$this->tournament_id}/matches");
    }

    public function reqShow($id)
    {
        return $this->request("/{$this->tournament_id}/matches/$id");
    }

    public function reqUpdate($id)
    {
        return $this->request("/{$this->tournament_id}/matches/$id", 'put');
    }

    /**
     * Function used to report the winner of a match
     */
    public function reportWinner($match_id, $winner_id, $scores)
    {
         $params = array();
         $params['match']['winner_id'] = $winner_id;
         $params['match']['scores_csv'] = $scores;
         $this->setParams($params);
         return $this->reqUpdate($match_id);
    }
}

