# $NetBSD: options.mk,v 1.3 2024/03/22 13:54:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fvwm3
PKG_SUPPORTED_OPTIONS=	svg doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-mandoc
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor	# asciidoctor
CONFIGURE_ENV+=	ac_cv_prog_ASCIIDOC=${PREFIX}/bin/asciidoctor${RUBY_VER}
.  include "../../lang/ruby/rubyversion.mk"
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-mandoc
.endif
