# $NetBSD: Makefile,v 1.18 2015/06/12 10:52:05 wiz Exp $

DISTNAME=	Jemplate-0.261
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RK/RKRIMEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Jemplate/
COMMENT=	Javascript Templating with Template Toolkit
LICENSE=	${PERL5_LICENSE}

PERL5_REQD+=	5.6.1

DEPENDS+=	p5-Template-Toolkit>=2.19:../../www/p5-Template-Toolkit
DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/Jemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
