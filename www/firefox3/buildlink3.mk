# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/06/28 10:01:06 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FIREFOX3_BUILDLINK3_MK:=	${FIREFOX3_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		firefox3
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfirefox3}
BUILDLINK_PACKAGES+=	firefox3
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}firefox3

.if !empty(FIREFOX3_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.firefox3+=	firefox3>=3.0
BUILDLINK_PKGSRCDIR.firefox3?=		../../www/firefox3
# XXX wip
GECKO_EXTRA_INC_DIRS= \
  . caps chardet commandhandler content docshell dom downloads exthandler \
  fastfind gfx gtkembedmoz intl js layout mimetype necko pipboot pipnss \
  shistory uriloader webbrowserpersist webbrwsr widget windowwatcher xpcom \
  xpconnect

GECKO_EXTRA_INCLUDE=	${GECKO_EXTRA_INC_DIRS:C,^,-I${BUILDLINK_PREFIX.firefox3}/include/firefox3/,}
.endif	# FIREFOX3_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
