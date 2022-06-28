# $NetBSD: Makefile,v 1.27 2022/06/28 11:37:17 wiz Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-DBIC-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Catalyst::Plugin::Session::Store::DBIC
COMMENT=	DBIC session storage backend
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.65000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Session-Store-Delegate>=0.05:../../www/p5-Catalyst-Plugin-Session-Store-Delegate
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBIx-Class>=0.07000:../../databases/p5-DBIx-Class
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/Store/DBIC/.packlist
 
## delete unnecessary (and harmfull) directory
post-extract:
	${RM} -rf ${WRKSRC}/PaxHeader

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
