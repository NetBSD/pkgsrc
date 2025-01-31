# $NetBSD: Makefile,v 1.1 2025/01/31 02:05:15 scole Exp $

PKGVER=		1.51
DISTNAME=	Tcl-Tk-${PKGVER}
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Tcl-Tk
COMMENT=	Extension module for Perl giving access to Tk via the Tcl extension
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tcl>=${PKGVER}:../../devel/p5-Tcl

PERL5_PACKLIST=		auto/Tcl/Tk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
