﻿#include "Application.h"

Loweb::Apps::Application::Application() : _parentApp(nullptr)
{
}

Loweb::Apps::Application::Application(Application* parentApp) : _parentApp(parentApp)
{
}

Loweb::Apps::Application::~Application()
{
	for (auto& item : _views)
	{
		if(item != nullptr)
			delete item;
	}

	for (auto& item : _apps)
	{
		if (item != nullptr)
			delete item;
	}
}

void Loweb::Apps::Application::AddView(const QString& path, Views::View* view)
{
	view->SetParentApp(this);
	view->SetAbsolutePath(path);
	_views.push_back(view);
}

void Loweb::Apps::Application::AddApplication(const QString& path, Application* app)
{
	app->SetParentApp(this);

	_apps[path] = app;
}

Loweb::Views::View* Loweb::Apps::Application::GetView(const QString& path)
{
	if (_views.contains(path))
		return _views[path];
	return nullptr;
}

Loweb::Apps::Application* Loweb::Apps::Application::GetApplication(const QString& path)
{
	if (_apps.contains(path))
		return _apps[path];
	return nullptr;
}

QMap<QString, Loweb::Apps::Application*>& Loweb::Apps::Application::GetApplications()
{
	return _apps;
}

void Loweb::Apps::Application::SetParentApp(Application* parentApp)
{
	_parentApp = parentApp;
}

void Loweb::Apps::Application::SetAbsolutePath(const QString& absolutePath)
{
	_absolutePath = absolutePath;
}

QString Loweb::Apps::Application::GetAbsolutePath()
{
	return _absolutePath;
}

Loweb::Apps::Application* Loweb::Apps::Application::GetParentApp()
{
	return _parentApp;
}
