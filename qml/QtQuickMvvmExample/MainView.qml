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
        text: "1st Source Text"
        font.pixelSize: 12
    }

    TextBox {
        id: srcTbx
        x: 150
        y: srcTxt.y
        width: 348
        height: 27;
        Binding { target: model; property: "sourceValue"; value: srcTbx.text }
    }


    // 2nd Source, sub data
    Text {
        x: srcTxt.x + 20
        y: srcTxt.y + 50
        text: "2nd Sub Text"
        font.pixelSize: 12
    }

    TextBox {
        id: subTbx
        x: srcTbx.x + 20
        y: srcTxt.y + 50
        width: 348
        height: 27;
//        Binding { target: subModel; property: "subData"; value: subTbx.text }
        Binding { target: model.mainModel.subModel; property: "subData"; value: subTbx.text }
//        text: model.destinationValue // ?? TODO
    }

    // 3rd Source, sub sub data
    Text {
        x: srcTxt.x + 40
        y: srcTxt.y + 100
        text: "3rd Sub Sub Text"
        font.pixelSize: 12
    }

    TextBox {
        id: subSubTbx
        x: srcTbx.x + 40
        y: srcTxt.y + 100
        width: 348
        height: 27;
        Binding { target: model.mainModel.subModel.subsubModel; property: "subSubData"; value: subSubTbx.text }
//        text: model.destinationValue  // ?? TODO
    }

    // destination data

    Text {
        x: srcTxt.x
        y: srcTxt.y + 300
        text: "Dest Text"
        font.pixelSize: 12
    }

    TextBox {
        id: destinationTbx
        x: srcTbx.x
        y: srcTxt.y + 300
        width: 348
        height: 27;
        text: model.destinationValue        
    }

    Button {
        x: srcTbx.x
        y: srcTxt.y + 400
        width: 113
        height: 37
        onClick: model.clearCommand()
    }
    Button {
        x: srcTbx.x + 200
        y: srcTxt.y + 400
        width: 113
        height: 37
        text: "show"
        onClick:  {
            console.log(model.sourceValue)
            console.log(model.mainModel.subModel.subData)
            console.log(model.mainModel.subModel.subsubModel.subSubData)
        }
    }
}
