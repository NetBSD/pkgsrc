# $NetBSD: Makefile,v 1.5 2015/01/12 09:46:50 mef Exp $

DISTNAME=	JSON-RPC-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-RPC/
COMMENT=	JSON RPC 2.0 Server implementation for Perl
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	perl:run

DEPENDS+=	p5-Class-Accessor-Lite-[0-9]*:../../devel/p5-Class-Accessor-Lite
DEPENDS+=	p5-HTTP-Daemon-[0-9]*:../../www/p5-HTTP-Daemon
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Router-Simple-[0-9]*:../../www/p5-Router-Simple
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

PERL5_PACKLIST=	auto/JSON/RPC/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
