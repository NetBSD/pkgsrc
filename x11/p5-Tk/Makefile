# $NetBSD: Makefile,v 1.36 2004/03/22 12:27:19 wiz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=	Tk-804.026
PKGNAME=	p5-Tk-804.026
SVR4_PKGNAME=	p5tk
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Tk/pod/overview.html
COMMENT=	Perl5 interface to Tk

BUILD_DEPENDS= 	p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

USE_BUILDLINK2=		YES
USE_X11=		YES
PERL5_REQD=		5.8
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/.packlist

MAKE_PARAMS=	X11=${X11BASE}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
