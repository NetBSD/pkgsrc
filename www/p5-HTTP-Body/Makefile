# $NetBSD: Makefile,v 1.1.1.1 2008/06/23 03:13:54 abs Exp $

DISTNAME=	HTTP-Body-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AG/AGRUNDMA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Body/
COMMENT=	HTTP Body Parser

DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
BUILD_DEPENDS+=	p5-File-Temp>=0.14:../../devel/p5-File-Temp
BUILD_DEPENDS+=	p5-YAML>=0.39:../../textproc/p5-YAML

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTTP/Body/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
