# $NetBSD: buildlink3.mk,v 1.29 2024/11/17 07:17:00 wiz Exp $

BUILDLINK_TREE+=	ocaml-lablgtk3

.if !defined(OCAML_LABLGTK3_BUILDLINK3_MK)
OCAML_LABLGTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lablgtk3+=	ocaml-lablgtk3>=3.0beta8
BUILDLINK_ABI_DEPENDS.ocaml-lablgtk3+=	ocaml-lablgtk3>=3.1.3nb16
BUILDLINK_PKGSRCDIR.ocaml-lablgtk3?=	../../x11/ocaml-lablgtk3

# options must be exposed if and only if we built with them
pkgbase := ocaml-lablgtk3
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.ocaml-lablgtk3:Mgtkspell}
.  include "../../textproc/gtkspell3/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ocaml-lablgtk3:Mgtksourceview3}
.  include "../../x11/gtksourceview3/buildlink3.mk"
.endif

.include "../../x11/gtk3/buildlink3.mk"
.endif	# OCAML_LABLGTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lablgtk3
