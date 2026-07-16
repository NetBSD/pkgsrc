# $NetBSD: Makefile,v 1.107 2026/07/16 19:06:24 wiz Exp $

DISTNAME=	Tk-804.036
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tk
COMMENT=	Perl5 interface to Tk

MAKE_JOBS_SAFE=	no

TOOL_DEPENDS+=	p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

USE_TOOLS+=		pkg-config
PERL5_PACKLIST=		auto/Tk/.packlist

MAKE_PARAMS=	X11=${X11BASE}

REPLACE_PERL+=		TextList/reindex.pl
REPLACE_PERL+=		pTk/Tcl-pTk
REPLACE_PERL+=		pTk/mkVFunc
REPLACE_PERL+=		demos/widget

CFLAGS+=	-Wno-incompatible-pointer-types

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
