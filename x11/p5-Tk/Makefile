# $NetBSD: Makefile,v 1.41.2.1 2005/02/19 21:47:14 snj Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=	Tk-804.027
PKGNAME=	p5-Tk-804.027
SVR4_PKGNAME=	p5tk
PKGREVISION=	2
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/htdocs/Tk/Tk.html
COMMENT=	Perl5 interface to Tk

BUILD_DEPENDS= 	p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_X11=	YES
PERL5_REQD=	5.8
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Tk/.packlist

MAKE_PARAMS=	X11=${X11BASE}

.include "../../lang/perl5/module.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
