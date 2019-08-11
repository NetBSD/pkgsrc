# $NetBSD: Makefile,v 1.61 2019/08/11 13:17:50 wiz Exp $

DISTNAME=	Wx-0.9932
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Wx
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

# All .so's "Invalid type identifier"
CTF_SUPPORTED=		no

BUILD_DEPENDS+=	p5-Alien-wxWidgets>=0.25:../../x11/p5-Alien-wxWidgets
#BUILD_DEPENDS+=	{perl>=5.16.6,p5-ExtUtils-ParseXS>=3.15}:../../devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS+=	p5-ExtUtils-XSpp>=0.16.02:../../devel/p5-ExtUtils-XSpp

#USE_TOOLS+=		gmake pkg-config wx-config
USE_TOOLS+=		perl
USE_LANGUAGES+=		c c++
PERL5_PACKLIST=		auto/Wx/.packlist

.include "../../lang/perl5/module.mk"
BUILDLINK_API_DEPENDS.wxGTK30+= wxGTK30>=3.0.3.1
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
