# $NetBSD: Makefile,v 1.3 2008/11/10 22:41:10 rhaen Exp $

DISTNAME=	Catalyst-Authentication-Store-DBIx-Class-0.1082
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Authentication-Store-DBIx-Class/
COMMENT=	Storage class for Catalyst Authentication using DBIx::Class

DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0.18:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10008:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=     	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class

PERL5_PACKLIST= auto/Catalyst/Authentication/Store/DBIx/Class/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
