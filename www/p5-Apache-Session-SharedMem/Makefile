# $NetBSD: Makefile,v 1.7 2018/08/22 09:47:28 wiz Exp $
#

DISTNAME=	Apache-Session-SharedMem-0.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-Session-SharedMem/
COMMENT=	Apache::Session module that stores session data in shared memory
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Apache-Session-[0-9]*:../../www/p5-Apache-Session
DEPENDS+=	p5-IPC-Cache-[0-9]*:../../devel/p5-IPC-Cache

PERL5_PACKLIST=	auto/Apache/Session/SharedMem/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
