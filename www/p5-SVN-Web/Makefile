# $NetBSD: Makefile,v 1.46 2022/06/28 11:37:42 wiz Exp $

DISTNAME=	SVN-Web-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DJ/DJZORT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SVN-Web
COMMENT=	Unstable snapshot of Subversion repository browser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Apache-DBI>=0.87:../../databases/p5-Apache-DBI
DEPENDS+=	p5-Date-Calc>=4.3:../../devel/p5-Date-Calc
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD
DEPENDS+=	p5-GD-Graph3d>=0.55:../../graphics/p5-GD-Graph3d
DEPENDS+=	p5-GDGraph>=1.33:../../graphics/p5-GDGraph
DEPENDS+=	p5-Locale-Maketext-Lexicon-[0-9]*:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Template-Plugin-Number-Format>=1.01:../../textproc/p5-Template-Plugin-Number-Format
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-Text-Diff>=0.35:../../textproc/p5-Text-Diff
DEPENDS+=	p5-Text-Diff-HTML>=0.04:../../textproc/p5-Text-Diff-HTML
DEPENDS+=	p5-Pod-POM-[0-9]*:../../textproc/p5-Pod-POM
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-DOM>=1.43:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-RSS>=0.9:../../textproc/p5-XML-RSS
DEPENDS+=	p5-XML-XPath>=1.08:../../textproc/p5-XML-XPath
DEPENDS+=	p5-XML-RSS>=0.97:../../textproc/p5-XML-RSS
DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML
DEPENDS+=	p5-subversion>=0.32.1:../../devel/p5-subversion
DEPENDS+=	subversion-base>=1.4:../../devel/subversion-base

# Recommended dependencies:
DEPENDS+=	p5-Template-Plugin-Clickable-[0-9]*:../../www/p5-Template-Plugin-Clickable
DEPENDS+=	p5-Template-Plugin-Clickable-Email-[0-9]*:../../www/p5-Template-Plugin-Clickable-Email
DEPENDS+=	p5-Template-Plugin-Subst-[0-9]*:../../www/p5-Template-Plugin-Subst

MAKE_PARAMS+=		--skip_questions -- "--installdirs vendor"
PERL5_PACKLIST=		auto/SVN/Web/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
