# $NetBSD: buildlink2.mk,v 1.8 2004/01/07 21:45:18 jmmv Exp $
#
# This Makefile fragment is included by packages that use wxGTK.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(WXGTK_BUILDLINK2_MK)
WXGTK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		wxGTK
BUILDLINK_DEPENDS.wxGTK?=	wxGTK>=2.4.1nb3
BUILDLINK_PKGSRCDIR.wxGTK?=	../../x11/wxGTK

EVAL_PREFIX+=			BUILDLINK_PREFIX.wxGTK=wxGTK
BUILDLINK_PREFIX.wxGTK_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.wxGTK+=	include/wx/*
BUILDLINK_FILES.wxGTK+=	include/wx/generic/*
BUILDLINK_FILES.wxGTK+=	include/wx/gtk/*
BUILDLINK_FILES.wxGTK+=	include/wx/html/*
BUILDLINK_FILES.wxGTK+=	include/wx/protocol/*
BUILDLINK_FILES.wxGTK+=	include/wx/unix/*

.include "../../mk/bsd.prefs.mk"

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
BUILDLINK_FILES.wxGTK+=	lib/libwx_gtk.*
BUILDLINK_FILES.wxGTK+=	lib/wx/include/gtk-2.4/wx/*
.include "../../x11/gtk/buildlink2.mk"
.else
BUILDLINK_FILES.wxGTK+=	lib/libwx_gtk2.*
BUILDLINK_FILES.wxGTK+=	lib/wx/include/gtk2-2.4/wx/*
.include "../../x11/gtk2/buildlink2.mk"
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

BUILDLINK_TARGETS+=	wxGTK-buildlink

wxGTK-buildlink: _BUILDLINK_USE

.endif	# WXGTK_BUILDLINK2_MK
