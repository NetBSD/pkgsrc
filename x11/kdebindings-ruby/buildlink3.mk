# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/10/12 11:44:55 markd Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
KDEBINDINGS_RUBY_BUILDLINK3_MK:=	${KDEBINDINGS_RUBY_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdebindings-ruby
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdebindings-ruby}
BUILDLINK_PACKAGES+=	kdebindings-ruby
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdebindings-ruby

.if ${KDEBINDINGS_RUBY_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdebindings-ruby+=	kdebindings-ruby>=3.5.5
BUILDLINK_PKGSRCDIR.kdebindings-ruby?=	../../x11/kdebindings-ruby
.endif	# KDEBINDINGS_RUBY_BUILDLINK3_MK

.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
