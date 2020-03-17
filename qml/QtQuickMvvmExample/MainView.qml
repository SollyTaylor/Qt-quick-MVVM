import QtQuick 2.0
import "Controls"

Rectangle {
    width: 600
    height: 480
    color: "#c4c4c4"

    // 1st Source
    Text {
        id : srcTxt
        x: 50
        y: 20
        text: "Main"
        font.pixelSize: 12
    }

    TextBox {
        id: srcTbx
        x: 150
        y: srcTxt.y
        width: 348
        height: 27;
        Binding { target: mainModel; property: "data"; value: srcTbx.text }
        Binding { target: srcTbx; property: "text"; value: mainModel.data  }
    }


    // 2nd Source, sub data
    Text {
        x: srcTxt.x + 20
        y: srcTxt.y + 50
        text: "SubData"
        font.pixelSize: 12
    }

    TextBox {
        id: subTbx
        x: srcTbx.x + 20
        y: srcTxt.y + 50
        width: 348
        height: 27;
        Binding { target: mainModel.subModel; property: "subData"; value: subTbx.text }
        Binding { target: subTbx; property: "text"; value: mainModel.subModel.subData }
    }

    // 3rd Source, sub sub data
    Text {
        x: srcTxt.x + 40
        y: srcTxt.y + 100
        text: "SubSubData"
        font.pixelSize: 12
    }

    TextBox {
        id: subSubTbx
        x: srcTbx.x + 40
        y: srcTxt.y + 100
        width: 348
        height: 27;
        Binding { target: mainModel.subModel.subsubModel; property: "subSubData"; value: subSubTbx.text }
        Binding { target: subSubTbx; property: "text"; value: mainModel.subModel.subsubModel.subSubData }
    }

    // destination data

    Text {
        x: srcTxt.x
        y: srcTxt.y + 300
        text: "Encrypted"
        font.pixelSize: 12
    }

    Text {
        id: destinationTbx
        x: srcTbx.x
        y: srcTxt.y + 300
        width: 348
        height: 27;
        text: mainModel.encrypted
    }

    Button {
        x: srcTbx.x
        y: srcTxt.y + 400
        width: 113
        height: 37
        onClick: mainModel.clearCommand()
    }

    Button {
        x: srcTbx.x + 200
        y: srcTxt.y + 400
        width: 113
        height: 37
        text: "show"
        onClick:  {
            console.log(mainModel.data)
            console.log(mainModel.subModel.subData)
            console.log(mainModel.subModel.subsubModel.subSubData)
        }
    }
}
