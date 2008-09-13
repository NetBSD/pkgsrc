# $NetBSD: Makefile,v 1.8 2008/09/13 15:59:37 he Exp $

DISTNAME=	Jemplate-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITES_PERL_CPAN:=../by-authors/id/I/IN/INGY/}

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
