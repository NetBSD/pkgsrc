# $NetBSD: Makefile,v 1.2 2003/12/07 01:50:11 epg Exp $

DISTNAME=	SVN-Web-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	epg@NetBSD.org
COMMENT=	Unstable snapshot of Subversion repository browser

DEPENDS+=	p5-subversion>=0.32.1:../../devel/p5-subversion
DEPENDS+=	p5-Template-Toolkit-2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Diff-0.35:../../textproc/p5-Text-Diff
DEPENDS+=	p5-XML-RSS-0.97:../../textproc/p5-XML-RSS
DEPENDS+=	p5-YAML-0.35:../../textproc/p5-YAML

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVN/Web/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
