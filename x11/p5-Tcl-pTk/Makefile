# $NetBSD: Makefile,v 1.6 2025/02/24 10:16:53 scole Exp $

DISTNAME=	Tcl-pTk-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Tcl::pTk
COMMENT=	Interface to Tcl/Tk with Perl/Tk compatible syntax
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tcl-[0-9]*:../../devel/p5-Tcl
DEPENDS+=	p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	tk-Tix-[0-9]*:../../x11/tk-Tix
DEPENDS+=	tklib-[0-9]*:../../devel/tklib

MAKE_PARAMS+=	--tclsh=${BUILDLINK_PREFIX.tcl}/bin/tclsh
MAKE_PARAMS+=	--no-test-for-tk

# xxx Img tests run but fail with this, maybe too old?
TEST_DEPENDS+=	tkimg-[0-9]*:../../graphics/tk-tkimg

PERL5_PACKLIST=		auto/Tcl/pTk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
