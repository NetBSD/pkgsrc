# $NetBSD: Makefile,v 1.48 2017/06/05 14:25:08 ryoon Exp $

DISTNAME=	Apache-ASP-2.62
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.apache-asp.org/
COMMENT=	Perl5/Apache module of Perl-coded Active Server Pages

DEPENDS+=	p5-Apache-Filter>=1.019:../../www/p5-Apache-Filter
DEPENDS+=	p5-Apache-SSI>=2.16:../../www/p5-Apache-SSI
#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib
DEPENDS+=	p5-Devel-Symdump>=2.00:../../devel/p5-Devel-Symdump
DEPENDS+=	p5-HTML-Clean>=0.8:../../www/p5-HTML-Clean
DEPENDS+=	p5-HTML-FillInForm>=0.8:../../www/p5-HTML-FillInForm
DEPENDS+=	p5-MLDBM>=2.00:../../databases/p5-MLDBM
DEPENDS+=	p5-MLDBM-Sync>=0.15:../../databases/p5-MLDBM-Sync
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=01.20}:../../time/p5-Time-HiRes
DEPENDS+=	p5-XML-XSLT>=0.32:../../textproc/p5-XML-XSLT
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww

REPLACE_PERL+=	ASP.pm

PERL5_PACKLIST=		auto/Apache/ASP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
