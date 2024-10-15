// Main3D.qml
import QtQuick
import QtQuick3D
import QtQuick.Window

View3D {
    anchors.fill: parent
    camera: PerspectiveCamera {
        position: Qt.vector3d(0, 200, 300)
        eulerRotation.x: -30
    }

    DirectionalLight {
        eulerRotation.x: -30
        eulerRotation.y: -70
    }

    Model {
        id: mpuModel
        source: "#Cube"
        position: Qt.vector3d(0, 0, 0)
        scale: Qt.vector3d(2, 0.5, 1)
        materials: [
            DefaultMaterial {
                diffuseColor: "green"
            }
        ]
    }

    Connections {
        target: serialHandler

        onDataUpdated: {
            // Misalnya, mengupdate rotasi berdasarkan data
            mpuModel.eulerRotation.x = parseFloat(roll)
            mpuModel.eulerRotation.y = parseFloat(pitch)
            mpuModel.eulerRotation.z = parseFloat(yaw)

            // Mengubah warna berdasarkan yaw
            if (parseFloat(yaw) > 45) {
                mpuModel.materials[0].diffuseColor = "red";
            } else if (parseFloat(yaw) > 0) {
                mpuModel.materials[0].diffuseColor = "yellow";
            } else {
                mpuModel.materials[0].diffuseColor = "green";
            }
        }
    }
}
