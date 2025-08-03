@startuml
GVSECore -> GVSECore: Early initialization steps
GVSECore -> GVSEDataManger: DataManager initalization (sigleton)
GVSECore -> GVSEWindowManager: Window initialization (singleton)
GVSEDataManger -> GVSEWindowManager: Provide window manager state data
GVSECore -> GVSEWindowManager: Signal window execution
GVSEWindowManager -> GVSEWindow: Process window
GVSEWindow -> GVSEWindowManager: Signal completion
GVSEWindowManager -> GVSEDataManger: Return modified data
GVSEWindowManager -> GVSECore: Signal window processing complete
@enduml
