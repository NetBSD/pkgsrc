# $NetBSD: Makefile,v 1.3 2026/01/10 04:00:03 scole Exp $

DISTNAME=	Tkx-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tkx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Tkx
COMMENT=	Yet another Perl5 Tk interface
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tcl-[0-9]*:../../devel/p5-Tcl
DEPENDS+=	p5-Test-Harness-Straps-[0-9]*:../../devel/p5-Test-Harness-Straps
DEPENDS+=	tk-BWidget-[0-9]*:../../x11/tk-BWidget
DEPENDS+=	tklib-[0-9]*:../../devel/tklib

PERL5_PACKLIST=		auto/Tkx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
