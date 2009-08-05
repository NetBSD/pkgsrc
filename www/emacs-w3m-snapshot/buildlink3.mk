# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/05 22:17:58 minskim Exp $
#

BUILDLINK_TREE+=	emacs-w3m

.if !defined(EMACS_W3M_BUILDLINK3_MK)
EMACS_W3M_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.emacs-w3m+=	${EMACS_PKGNAME_PREFIX}emacs-w3m>=1.4.364
BUILDLINK_PKGSRCDIR.emacs-w3m?=		../../www/emacs-w3m-snapshot

BUILDLINK_CONTENTS_FILTER.emacs-w3m=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # EMACS_W3M_BUILDLINK3_MK

BUILDLINK_TREE+=	-emacs-w3m
