byCar(auckland,hamilton).
byCar(hamilton,raglan).
byCar(valmont,saarbruecken).
byCar(valmont,metz).

byTrain(metz,frankfurt).
byTrain(saarbruecken,frankfurt).
byTrain(metz,paris).
byTrain(saarbruecken,paris).
           
byPlane(frankfurt,bangkok).
byPlane(frankfurt,singapore).
byPlane(paris,losAngeles).
byPlane(bangkok,auckland).
byPlane(losAngeles,auckland).

% Question 2
% travel(X,Y):- byCar(X,Y).
% travel(X,Y):- byTrain(X,Y).
% travel(X,Y):- byPlane(X,Y).

% travel(X,Y):- travel(X,Z), travel(Z,Y).

% Question 3
travelRoute(X,Y,go(X,Y)) :- byCar(X,Y).
travelRoute(X,Y,go(X,Y)) :- byTrain(X,Y).
travelRoute(X,Y,go(X,Y)) :- byPlane(X,Y).
travelRoute(X,Y,go(X,Z,G)) :- 
    travelRoute(X,Z,go(X,Z)), travelRoute(Z,Y,G).

% Question 4
travel3(X,Y,go(X,Y, car)) :- byCar(X,Y).
travel3(X,Y,go(X,Y, train)) :- byTrain(X,Y).
travel3(X,Y,go(X,Y, plane)) :- byPlane(X,Y).
travel3(X,Y,go(X,Z,Tran, G)) :- 
    travel3(X,Z,go(X,Z, Tran)), travel3(Z,Y,G).
