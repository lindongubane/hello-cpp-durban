#include <Wt/WApplication.h>
#include <Wt/WGroupBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WBootstrapTheme.h>
#include <memory>

// Based on code from the following sample: https://www.webtoolkit.eu/wt/src/hello

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env)
    {
        auto app = std::make_unique<Wt::WApplication>(env);
        app->setCssTheme("bootstrap");
        auto theme = std::make_shared<Wt::WBootstrapTheme>();
        theme->setVersion(Wt::BootstrapVersion::v3);
        app->setTheme(theme);
        app->setTitle("Hello world");

        auto* root = app->root();

        auto* panel = root->addNew<Wt::WContainerWidget>();

        panel->setStyleClass("col-md-6 col-md-offset-3");

        auto* buttonGroup = panel->addNew<Wt::WContainerWidget>();
        buttonGroup->setStyleClass("input-group");

        auto* nameEdit = buttonGroup->addNew<Wt::WLineEdit>(); // allow text input
        nameEdit->setPlaceholderText("Add a new item");
        nameEdit->setFocus();

        auto* addon = buttonGroup->addNew<Wt::WContainerWidget>();
        addon->setInline(true);
        addon->setStyleClass("input-group-btn");

        auto button = addon->addNew<Wt::WPushButton>("Add");

        auto* items = panel->addNew<Wt::WGroupBox>("To-do list");

        const auto greet = [=] ()
        {
            items->addNew<Wt::WText>(nameEdit->text());
            items->addNew<Wt::WBreak>();
            nameEdit->setText("");
        };

        button->clicked().connect(greet);
        nameEdit->enterPressed().connect(greet);

        return app;
    });
}