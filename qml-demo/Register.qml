import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Rectangle {

    anchors.fill: parent
    visible: false
    color: "#f0f0f0"  // 添加背景色
    Column{
        spacing: 30
        anchors.centerIn: parent  // 整体居中

        Label{
            text: "用户注册"
            font.family: "微软雅黑"
            font.pointSize: 20
            horizontalAlignment: Text.AlignHCenter
            rightPadding: 0
            leftPadding: 0
        }

        Row{
            spacing: 20

            Label{
                text: "用 户 名:"
                font.family: "微软雅黑"
                font.pointSize: 16
                width: 80
                height: 15
            }
            TextField{
                font.family: "微软雅黑"
                font.pointSize: 16
                width: 180
                height: 40
                placeholderText: "请输入用户名"

            }
        }

        Row{
            spacing: 20
            Label{
                text: "密   码:"
                font.family: "微软雅黑"
                font.pointSize: 16
                width: 80
                height: 40
            }
            TextField{
                font.family: "微软雅黑"
                font.pointSize: 16
                width: 180
                height: 40
                placeholderText: "请输入密码"

            }
        }

        Row{
            spacing: 20
            Label{
                text: "确认密码:"
                font.family: "微软雅黑"
                font.pointSize: 16
                width: 80
                height: 40
            }
            TextField{
                font.family: "微软雅黑"
                font.pointSize: 16
                width: 180
                height: 40
                placeholderText: "请再次输入密码"

            }
        }

        Row{
            spacing: 50
            Button{
                id:register
                text: "注册"
                width: 100
                height: 40
                font.family: "微软雅黑"
                font.pointSize: 14
                background: Rectangle {
                    color: "#4a86e8"
                    radius: 4
                    border.color: "#3a76d8"
                    border.width: 1
                }
            }
            Button{
                id:back
                text: "取消"
                width: 100
                height: 40
                font.family: "微软雅黑"
                font.pointSize: 14
                background: Rectangle {
                    color: "#6aa84f"
                    radius: 4
                    border.color: "#5a983f"
                    border.width: 1
                }
                onClicked: {
                    registerpage.visible=false
                    loginpage.visible=true
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
