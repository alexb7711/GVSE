@startuml
package GVSE
{
        package GVSEManager 
        {
                object GVSEWindowManager
                GVSEWindowManager : windows

                object GVSEDataManager
                GVSEDataManager : data_objects
        }

        package Windows
        {
                object 2DMapView
                2DMapView : position
                2DMapView : orientation
                2DMapView : speed

                object PlotView
                PlotView : JSON_Data
                PlotView : UDP_TCP_Data

                object TableView
                TableView : JSON_Data
                TableView : UDP_TCP_Data
        }
}

package VehicleSimulation
{
        object VehicleState
        VehicleState : position
        VehicleState : orientation
        VehicleState : speed
        VehicleState : mode

        object VehicleRoute
        VehicleRoute : route_path

        object Vehicle
        Vehicle : model
}

object JSON
object UDP_TCP

VehicleSimulation --> UDP_TCP : Public 'Published' Data
VehicleSimulation --> JSON    : Private 'Internal' Data
VehicleSimulation --> GVSE    : Adding data directly via library

UDP_TCP --> GVSE 
JSON --> GVSE
GVSE --> GVSEManager : Pass data to the manager


GVSEManager --> Windows : Provide window placement and data

@enduml

