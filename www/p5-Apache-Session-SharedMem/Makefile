# $NetBSD: Makefile,v 1.5 2017/06/05 14:25:08 ryoon Exp $
#

DISTNAME=	Apache-Session-SharedMem-0.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-Session-SharedMem/
COMMENT=	Apache::Session module that stores session data in shared memory
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Apache-Session-[0-9]*:../../www/p5-Apache-Session
DEPENDS+=	p5-IPC-Cache-[0-9]*:../../devel/p5-IPC-Cache

PERL5_PACKLIST=	auto/Apache/Session/SharedMem/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
