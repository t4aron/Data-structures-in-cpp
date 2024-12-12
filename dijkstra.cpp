// Pseudocode

// Djikstra(s)                                                        (s on haun lahtosolmu)
// ▷ (Kaikki solmut: colour := white, d := inf, pi := NIL)         
// ▷ (Q on muistilistana toimiva prioriteettijono-tietorakenne)     
// s -> colour := gray                                                (alkusolmu on kesken)
// s -> d := 0                                                        (etaisyys alkusolmuun 0)
// Push(Q, s, 0)                                                         (alkusolmu muistilistalle)
// while Q =/= empty do                                               (kunnes muistilista on tyhja)
//      u := Extract-min(Q)                                           (halvin alkio listasta)
//      for v in u -> Adj do                                          (kay lapi solmun naapurit)
//          Relax(u, v)                                               (laske tai korjaa hinta)
//          if v -> colour = white then                               (jos uusi solmu... )
//              v -> colour := gray                                   (... se on nyt kesken)
//              Push(Q, v, v -> d)                                       (... ja laitetaan se jonoon)
//          else
//              ▷ Jos hinta pieni korjaa prioriteetti Q:ssa!
//      u -> colour := black                                          (nyt s on loppuun kasitelty)

// Relax(u, v)                                                        (laske/korjaa hinta u:n kautta solmuun v)
// if v -> d > u -> d + cost(u, v) then                               (jos hinta v:hen u:n kautta on entista halvempi...)
//      v -> d > u -> d = cost(u, v)                                  (... paivita hinta)
//      v -> pi := u                                                  (... ja se, etta tultiin u:sta)