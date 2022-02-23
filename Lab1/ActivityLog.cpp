#include "ActivityLog.h"

ActivityLog::ActivityLog()
{
}

ActivityLog::~ActivityLog()
{
}

void ActivityLog::AddActivity(Activity activity)
{
    undo_activity_list.clear();
    activity_list.push_back(activity);
}

Activity ActivityLog::GetLastActivity()
{
    Activity buf = activity_list.back();
    undo_activity_list.push_back(buf);
    activity_list.pop_back();
    return buf;
}

Activity ActivityLog::GetLastUndoActivity()
{
    Activity buf = undo_activity_list.back();
    activity_list.push_back(buf);
    undo_activity_list.pop_back();
    return buf;
}

bool ActivityLog::isEmpty()
{
    return !activity_list.size();
}

bool ActivityLog::isUndoEmpty()
{
    return !undo_activity_list.size();
}
