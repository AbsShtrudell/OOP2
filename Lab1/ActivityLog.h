#pragma once
#include <list>

using namespace std;

enum ActivityType
{
	MoveCursor,
	BackSpace,
	Print
};

struct Activity
{
	ActivityType type;
	int value;
};

class ActivityLog
{
private:
	list<Activity> activity_list;
	list<Activity> undo_activity_list;
public:
	ActivityLog();
	~ActivityLog();

	void AddActivity(Activity activity);
	Activity GetLastActivity();
	Activity GetLastUndoActivity();
	bool isEmpty();
	bool isUndoEmpty();
};

