import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5



Rectangle {
    anchors.fill: parent

    color: "#f0f0f0"  // 添加背景色
    // 垂直布局
    Column {
        id: layout
        anchors.centerIn: parent  // 整体居中
        spacing: 25
        width: parent.width * 0.7  // 使用父容器比例宽度
        // 标题
        Label {

            text: "用户登录"
            horizontalAlignment: Text.AlignHCenter
            rightPadding: 0
            leftPadding: 0
            font.family: "微软雅黑"
            font.pointSize: 20
            font.bold: true
            width: parent.width
            height: 50
        }

        // 用户名行
        Row {
            id: username
            width: parent.width * 0.8
            height: 50
            spacing: 30

            Label {
                id: name
                text: "用户名:"
                font.family: "微软雅黑"
                color: "#000000"
                font.pointSize: 14
                width: parent.width * 0.2

            }

            TextField {
                id: nameinput
                width: parent.width * 0.8
                height: 40
                placeholderText: "请输入用户名"
                font.family: "微软雅黑"
                font.pointSize: 14

                background: Rectangle {
                    color: "white"
                    border.color: "#cccccc"
                    border.width: 1
                    radius: 4
                }
            }
        }

        // 密码行
        Row {
            id: pwdRow
            width: parent.width * 0.8
            height: 50
            spacing: 30

            Label {
                id: psword
                text: "密   码:"
                font.family: "微软雅黑"
                font.pointSize: 14
                width: parent.width * 0.2
                height: 30
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: pwdinput
                width: parent.width * 0.8
                height: 40
                placeholderText: "请输入密码"
                font.family: "微软雅黑"
                font.pointSize: 14
                echoMode: TextInput.Password  // 设置密码隐藏显示

                background: Rectangle {
                    color: "white"
                    border.color: "#cccccc"
                    border.width: 1
                    radius: 4
                }
            }
        }

        // 按钮行
        Row {
            id: btns
            width: parent.width
            height: 50
            layoutDirection: Qt.LeftToRight
            spacing: 190
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                id: btnlogin
                width: 100
                height: 40
                text: "登录"
                font.family: "微软雅黑"
                font.pointSize: 14
                background: Rectangle {
                    color: "#4a86e8"
                    radius: 4
                    border.color: "#3a76d8"
                    border.width: 1
                }
                onClicked: {
                    console.log("登录按钮被点击，用户名:", nameinput.text, "密码:", pwdinput.text)
                    // 这里可以添加登录逻辑
                    var username=nameinput.text
                    var pwd=pwdinput.text
                    if(username=="admin" && pwd=="123456")
                    {
                        loginpage.visible = false
                        mainpage.visible = true
                        console.log("登陆成功")
                    }
                    else{
                        console.log("登陆失败")
                    }
                }
            }

            Button {
                id: btnregister
                width: 100
                height: 40
                text: "注册"
                font.family: "微软雅黑"
                font.pointSize: 14
                background: Rectangle {
                    color: "#6aa84f"
                    radius: 4
                    border.color: "#5a983f"
                    border.width: 1
                }
                onClicked: {
                    console.log("注册按钮被点击")
                    // 这里可以添加注册逻辑
                    registerpage.visible=true
                    loginpage.visible=false
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
