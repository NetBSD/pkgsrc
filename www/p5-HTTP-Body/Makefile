# $NetBSD: Makefile,v 1.5 2010/01/17 00:31:27 sno Exp $

DISTNAME=	HTTP-Body-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Body/
COMMENT=	HTTP Body Parser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Temp>=0.14:../../devel/p5-File-Temp
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.86}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTTP/Body/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
