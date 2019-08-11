# $NetBSD: Makefile,v 1.16 2019/08/11 13:25:06 wiz Exp $

DISTNAME=		WordPress-XMLRPC-2.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www net
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=WordPress/}

MAINTAINER=		imil@gcu.info
HOMEPAGE=		https://metacpan.org/release/WordPress-XMLRPC
COMMENT=		Perl 5 API to WordPress XML-RPC services
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-LEOCHARRE-CLI2-[0-9]*:../../devel/p5-LEOCHARRE-CLI2
DEPENDS+=		p5-LEOCHARRE-Debug-[0-9]*:../../devel/p5-LEOCHARRE-Debug
DEPENDS+=		p5-SOAP-Lite>=0.71.08:../../net/p5-SOAP-Lite
DEPENDS+=		p5-Smart-Comments-[0-9]*:../../devel/p5-Smart-Comments
DEPENDS+=		p5-YAML-[0-9]*:../../textproc/p5-YAML

PERL5_PACKLIST=		auto/WordPress/XMLRPC/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
