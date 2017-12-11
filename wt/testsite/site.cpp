#include <Wt/WAnchor.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WText.h>

using namespace Wt;

class ControlExample: public WApplication {
private:
    std::string appName;
    WContainerWidget* _content;

public:
    ControlExample(const WEnvironment &env): WApplication(env) {
        appName = "Application Name";
        setTitle(appName);
        _content = 0;
        internalPathChanged().connect(this, &ControlExample::onInternalPathChange);

        header();
        home();
        sidebar();
        footer();
    }

    WContainerWidget* content() {
        if (_content == 0) {
            _content = new WContainerWidget(root());
            _content->setId("content");
        }
        return _content;
    }

    void onInternalPathChange() {
        content()->clear();
        if (internalPath() == "/") {
            home();
        }
        else if (internalPath() == "/page1") {
            page1();
        }
    }

    void header() {
        WContainerWidget* header = new WContainerWidget(root());
        header->setId("header");
        header->addWidget(new WText("<h1>" + appName + "</h1>"));
    }

    void sidebar() {
        WContainerWidget* sidebar = new WContainerWidget(root());
        sidebar->setId("sidebar");
        sidebar->addWidget(new WText("Sidebar Information"));
    }

    void footer() {
        WContainerWidget* footer = new WContainerWidget(root());
        footer->setId("footer");
        footer->addWidget(new WText("Developed using C++/Wt"));
    }

    void home() {
        WText *t = new WText("<strong>Home</strong> content and a link to <a href='#/page1'>page1</a>");
        t->setInternalPathEncoding(true);
        content()->addWidget(t);

    }

    void page1() {
        content()->addWidget(new WText("<strong>Home</strong> content and a link to "));
        WAnchor* a = new WAnchor(WLink(WLink::InternalPath, "/"), "home", content());
    }

};

WApplication* createApplication(const WEnvironment &env) {
    return new ControlExample(env);
}

int main(int argc, char** argv) {
    return WRun(argc, argv, &createApplication);
}
