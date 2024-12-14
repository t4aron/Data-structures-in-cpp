// Halvimmat reitit: A* ja heuristiikat

// A*(s, g)                                                           (s on haun lahtosolmu, g maali)
// ▷ (Kaikki solmut: colour := white, d := inf, de := inf, pi := NIL)         
// ▷ (Q on muistilistana toimiva prioriteettijono-tietorakenne)     
// s -> colour := gray                                                (alkusolmu on kesken)
// s -> d := 0                                                        (etaisyys alkusolmuun 0)
// Push(Q, s, 0)                                                      (alkusolmu muistilistalle)
// while Q =/= empty do                                               (kunnes muistilista on tyhja)
//      u := Extract-min(Q)                                           (halvin alkio listasta)
//      for v in u -> Adj do                                          (kay lapi solmun naapurit)
//          Relax-A*(u, v, g)                                            (laske tai korjaa hinta)
//          if v -> colour = white then                               (jos uusi solmu... )
//              v -> colour := gray                                   (... se on nyt kesken)
//              Push(Q, v, v -> de)                                   (... ja laitetaan se jonoon)
//          else
//              ▷ Jos hinta pieni korjaa prioriteetti Q:ssa!
//      u -> colour := black                                          (nyt s on loppuun kasitelty)

// Relax-A*(u, v)                                                        (laske/korjaa hinta + arvio u:n kautta solmuun v)
// if v -> d > u -> d + cost(u, v) then                               (jos hinta v:hen u:n kautta on entista halvempi...)
//      v -> d > u -> d = cost(u, v)                                  (... paivita hinta)
//      v -> de := v -> d + min-est(v, g)                             (... päivitä minimi arvio kokonaishinnasta)
//      v -> pi := u                                                  (... ja se, etta tultiin u:sta)

// Djikstran toteutus edellyttaa minimi-prioriteettijonon
// STL:ssa on valmiiksi std::priority_queue maksimiprioriteettijono
// Tallennetaan prioriteetiksi -d tai mukautetaan prioriteettijonoa