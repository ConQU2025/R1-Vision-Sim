
"use strict";

let GetChargerByName = require('./GetChargerByName.js')
let AddNewWaypoint = require('./AddNewWaypoint.js')
let SaveWaypoints = require('./SaveWaypoints.js')
let GetWaypointByName = require('./GetWaypointByName.js')
let GetNumOfWaypoints = require('./GetNumOfWaypoints.js')
let GetWaypointByIndex = require('./GetWaypointByIndex.js')

module.exports = {
  GetChargerByName: GetChargerByName,
  AddNewWaypoint: AddNewWaypoint,
  SaveWaypoints: SaveWaypoints,
  GetWaypointByName: GetWaypointByName,
  GetNumOfWaypoints: GetNumOfWaypoints,
  GetWaypointByIndex: GetWaypointByIndex,
};
