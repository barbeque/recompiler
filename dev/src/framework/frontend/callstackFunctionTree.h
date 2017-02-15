#pragma once

class CCallstackFunctionTree : public wxTreeListCtrl
{
	DECLARE_EVENT_TABLE();

public:
	enum EIcon
	{
		eIcon_Closed,
		eIcon_Opened,
	};

	CCallstackFunctionTree( wxWindow* parent );
	~CCallstackFunctionTree();

	// highlight trace index
	void Highlight( const uint32 traceEntry );

	// rebuild tree
	void Rebuild( const class trace::CallTree* callstackData, const uint32 maxRecursion, const bool unmangleFunctionNames );

private:
	// range search
	wxTreeListItem FindItemForRange( wxTreeListItem parent, const uint32 traceIndex );

	// events
	void OnItemDoubleClick( wxTreeListEvent& event );

	// last selected
	wxTreeListItem		m_highlighted;
};