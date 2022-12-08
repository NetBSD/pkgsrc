# $NetBSD: buildlink3.mk,v 1.7 2022/12/08 15:22:02 tsutsui Exp $

BUILDLINK_TREE+=	ruby-gtk3

.if !defined(RUBY_GTK3_BUILDLINK3_MK)
RUBY_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=4.0.3
BUILDLINK_ABI_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=4.0.3
BUILDLINK_PKGSRCDIR.ruby-gtk3?=		../../x11/ruby-gtk3

.include "../../graphics/ruby-gdk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gtk3
