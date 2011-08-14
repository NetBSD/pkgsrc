# $NetBSD: Makefile,v 1.5 2011/08/14 16:05:51 obache Exp $

DISTNAME=	CatalystX-CRUD-View-Excel-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-CRUD-View-Excel/
COMMENT=	View CRUD search/list results in Excel format
LICENSE=	${PERL5_LICENSE}

DEPENDS+=       p5-CatalystX-CRUD>=0.27:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-Catalyst-View-Excel-Template-Plus-[0-9]*:../../www/p5-Catalyst-View-Excel-Template-Plus
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/View/Excel/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
