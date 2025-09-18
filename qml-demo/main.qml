import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5  // 更新Controls版本以获取更好的组件
import "./"

Window {
    visible: true
    width: 500
    height: 400
    title: qsTr("主页面")
    Login{
        id:loginpage
        visible: true
    }
    Register{
        id:registerpage
        visible: false
    }
    Rectangle{
        anchors.fill: parent
        id:mainpage
        visible: false


        Button{
            id:exit
            text: "退出登录"
            width: 100
            height: 50
            anchors.centerIn: parent
            onClicked: {
                mainpage.visible=false
                loginpage.visible=true
            }
        }
    }
}
