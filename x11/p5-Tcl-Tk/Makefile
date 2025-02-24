# $NetBSD: Makefile,v 1.4 2025/02/24 03:53:39 scole Exp $

PKGVER=		1.51
DISTNAME=	Tcl-Tk-${PKGVER}
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Tcl-Tk
COMMENT=	Extension module for Perl giving access to Tk via the Tcl extension
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tcl>=${PKGVER}:../../devel/p5-Tcl
DEPENDS+=	tcllib-[0-9]*:../../devel/tcllib
DEPENDS+=	tklib-[0-9]*:../../devel/tklib

MAKE_PARAMS+=	--tclsh=${BUILDLINK_PREFIX.tcl}/bin/tclsh
MAKE_PARAMS+=	--no-test-for-tk

PERL5_PACKLIST=		auto/Tcl/Tk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
