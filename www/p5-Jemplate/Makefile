# $NetBSD: Makefile,v 1.25 2019/08/11 13:24:49 wiz Exp $

DISTNAME=	Jemplate-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/I/IN/INGY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Jemplate
COMMENT=	Javascript Templating with Template Toolkit
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Template-Toolkit>=2.19:../../www/p5-Template-Toolkit
DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/Jemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
