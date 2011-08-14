# $NetBSD: Makefile,v 1.12 2011/08/14 16:05:59 obache Exp $

DISTNAME=	Jemplate-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RK/RKRIMEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Jemplate/
COMMENT=	Javascript Templating with Template Toolkit

PERL5_REQD+=	5.6.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Template-Toolkit>=2.19:../../www/p5-Template-Toolkit
DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/Jemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
