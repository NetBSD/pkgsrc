# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:36 joerg Exp $
#

BUILDLINK_TREE+=	emacs-w3m

.if !defined(EMACS_W3M_BUILDLINK3_MK)
EMACS_W3M_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.emacs-w3m+=	${EMACS_PKGNAME_PREFIX}emacs-w3m>=1.4
BUILDLINK_PKGSRCDIR.emacs-w3m?=	../../www/emacs-w3m

BUILDLINK_CONTENTS_FILTER.emacs-w3m=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # EMACS_W3M_BUILDLINK3_MK

BUILDLINK_TREE+=	-emacs-w3m
