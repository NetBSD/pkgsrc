# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:36 joerg Exp $

BUILDLINK_TREE+=	firefox3

.if !defined(FIREFOX3_BUILDLINK3_MK)
FIREFOX3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firefox3+=	firefox3>=3.0
BUILDLINK_PKGSRCDIR.firefox3?=		../../www/firefox3
# XXX wip
GECKO_EXTRA_INC_DIRS= \
  . caps chardet commandhandler content docshell dom downloads exthandler \
  fastfind gfx gtkembedmoz intl js layout mimetype necko pipboot pipnss \
  shistory uriloader webbrowserpersist webbrwsr widget windowwatcher xpcom \
  xpconnect

GECKO_EXTRA_INCLUDE=	${GECKO_EXTRA_INC_DIRS:C,^,-I${BUILDLINK_PREFIX.firefox3}/include/firefox3/,}
.endif # FIREFOX3_BUILDLINK3_MK

BUILDLINK_TREE+=	-firefox3
